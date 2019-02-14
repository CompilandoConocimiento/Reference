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

/**
   * A wrapper to each code block that controls when to show loading or
   * when to show the code and to call hljs highlightBlock
   */
class CodeWrapper extends React.Component<CodeProps, CodeState> {

    constructor(props: CodeProps) { 
        super(props)
        this.state = { codeMonted: CodeStatus.Loading }
    }

    /** call highlightBlock? */
    componentDidUpdate() {
        if (this.state.codeMonted == CodeStatus.WaitingBlockUpdate) {
            const ID = this.props.fileName + this.props.partOfFile
            window["hljs"].highlightBlock(document.getElementById(ID))
            this.setState({codeMonted: CodeStatus.Ready})
        }
    }

    /** Is code mounted? */
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


/** A function that decided if the code theme is loaded if not we downloaded */
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

/** A component to show code */
const ShowCode: React.FunctionComponent<ShowCodeProps> = props => {
    const {theme, fontSize} = props.Config.CodeStyles
    loadTheme(theme)

    const PreStyle  = {fontSize: `${fontSize}rem`, margin: "16px 0px", padding: "20px", borderRadius: "4px"}
    const CodeStyle = {fontFamily: "firacode"}

    let elevation: any = props.Config.CodeStyles.elevation
    elevation = (!(!elevation))? "z-depth-1 hoverable " : ""

    const CardProps = {
        onDoubleClick: () => copyText(props.Text),
        className: elevation + Styles.HideScrollbars
    }

    return (
        <pre id={props.ID} style={PreStyle} {...CardProps}>
            <code style={CodeStyle}>
                {props.Text.join("\n")}
            </code>
        </pre>
    )
} 


export default CodeWrapper