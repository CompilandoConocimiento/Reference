import React from "react"

import { FilesDataResult, CodeConfig } from "../../Data"
import { Loading }   from "../Helpers"
import { copyText }  from "./CodeActions"
import ConfigContext from "./ConfigContext"

import * as Styles   from "./Styles.css"

enum CodeStatus { Loading, WaitingBlockUpdate, Ready }
interface CodeState { codeMonted: CodeStatus }
interface CodeProps {
    Data: FilesDataResult | undefined,
    fileName: string,
    partOfFile: string,
}

class CodeWrapper extends React.Component<CodeProps, CodeState> {

    constructor(props: CodeProps) { 
        super(props)
        this.state = { codeMonted: CodeStatus.Loading }
    }

    componentDidUpdate() {
        if (this.state.codeMonted == CodeStatus.WaitingBlockUpdate) {
            const ID = this.props.fileName + this.props.partOfFile
            window["hljs"].highlightBlock(document.getElementById(ID))
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
                { Config => <ShowCode ID={this.props.fileName + this.props.partOfFile} Text={Text} Config={Config} /> }
            </ConfigContext.Consumer>
        )
    }
}


export function loadTheme(theme: string) {
    if (window["theme"] && window["theme"] === theme) return 
    if (theme === "") return 

    const themeLink = document.getElementById("HighlightCSS")!
    themeLink["href"] =`https://cdnjs.cloudflare.com/ajax/libs/highlight.js/9.12.0/styles/${theme}.min.css`
    window["theme"] = theme
}


interface ShowCodeProps {
    Text: string[],
    ID: string,
    Config: CodeConfig,
}

const ShowCode: React.FunctionComponent<ShowCodeProps> = props => {
    const {theme, fontSize} = props.Config.CodeStyles
    loadTheme(theme)

    const PreStyle  = {fontSize: `${fontSize}rem`, margin: "16px 0px", padding: "20px", borderRadius: "4px"}
    const CodeStyle = {fontFamily: "firacode"}

    const CardActions = {
        onDoubleClick: () => copyText(props.Text),
    }

    return (
        <pre id={props.ID} style={PreStyle} {...CardActions} className={"z-depth-1 hoverable " + Styles.HideScrollbars}>
            <code style={CodeStyle}>
                {props.Text.join("\n")}
            </code>
        </pre>
    )
} 


export default CodeWrapper