import React from "react"

import { FilesDataResult, CodeConfig } from "../../Data"
import { Loading }   from "../Helpers"
import { copyText }  from "./CodeActions"
import ConfigContext from "./ConfigContext"

import * as Styles   from "./Styles.css"

enum CodeStatus { Loading, WaitingBlockUpdate, Ready }
interface CodeState { codeMonted: CodeStatus }
interface CodeProps {
    ID: string,
    Data: FilesDataResult | undefined,
    fileName: string,
    partOfFile: number,
}

class CodeWrapper extends React.Component<CodeProps, CodeState> {

    constructor(props: CodeProps) { 
        super(props)
        this.state = { codeMonted: CodeStatus.Loading }
    }

    componentDidUpdate() {
        if (this.state.codeMonted == CodeStatus.WaitingBlockUpdate) {
            window["hljs"].highlightBlock(document.getElementById(this.props.ID))
            this.setState({codeMonted: CodeStatus.Ready})
        }
    }

    static getDerivedStateFromProps(props: CodeProps, state: CodeState) {
        if (state.codeMonted != CodeStatus.Loading) return null
        if (!props.Data || !props.Data[props.fileName]) return null
        if (!props.Data[props.fileName][props.partOfFile]) return null

        return {codeMonted: CodeStatus.WaitingBlockUpdate}
    }

    render() {
        if (this.state.codeMonted == CodeStatus.Loading) return <Loading />
        const Text = this.props.Data![this.props.fileName][this.props.partOfFile]

        return (
            <ConfigContext.Consumer>
                { Config => <ShowCode ID={this.props.ID} Text={Text} Config={Config} /> }
            </ConfigContext.Consumer>
        )
    }
}

interface ShowCodeProps {
    Text: string[],
    ID: string,
    Config: CodeConfig,
}

const ShowCode: React.FunctionComponent<ShowCodeProps> = props => {
    const {backgroundColor, fontSize} = props.Config.CodeStyles
    const CardStyle = {backgroundColor: backgroundColor, padding: "16px"}
    const PreStyle  = {fontSize: `${fontSize}rem`, margin: "0px", backgroundColor: "transparent"}
    const CodeStyle = {fontFamily: "firacode"}

    const CardActions = {
        onDoubleClick: () => copyText(props.Text),
        style: CardStyle,
    }

    return (
        <div className="card-panel hoverable" {...CardActions}>
            <pre id={props.ID} style={PreStyle} className={Styles.HideScrollbars}>
                <code style={CodeStyle}>
                    {props.Text.join("\n")}
                </code>
            </pre>
        </div>
    )
} 

export default CodeWrapper