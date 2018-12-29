import React from "react"
import { FilesDataResult, CodeStyles, CodeActions } from "../../Data"

import { copyText } from "./CodeActions"
import * as Styles from "./Styles.css"

enum CodeStatus { Loading, WaitingBlockUpdate, Ready }
interface CodeState {codeMonted: CodeStatus}
interface CodeProps {
    ID: string,
    Data: FilesDataResult | undefined,
    fileName: string,
    partOfFile: number,
    codeActions: CodeActions,
    codeStyles: CodeStyles
}

class ShowCode extends React.Component<CodeProps, CodeState> {

    constructor(props: CodeProps) { 
        super(props)
        this.state = {codeMonted: CodeStatus.Loading}
    }

    componentDidUpdate() {
        if (this.state.codeMonted == CodeStatus.WaitingBlockUpdate) {
            window["hljs"].highlightBlock( document.getElementById(this.props.ID) )
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

        if (this.state.codeMonted == CodeStatus.Loading) 
            return (
                <div className="row">
                    <div className="col s8 offset-s2">
                        <div className="progress">
                            <div className="indeterminate"></div>
                        </div>
                    </div>
                </div>
            )
        
        const Text = this.props.Data![this.props.fileName][this.props.partOfFile]

        return (
            <div className="row card-panel hoverable" style={{backgroundColor: "#2b2b2b"}} onDoubleClick={() => copyText(Text)}>
                <div className="row">
                    <pre id       = {this.props.ID} 
                        style     = {{fontSize: `${this.props.codeStyles.fontSize}rem`}} 
                        className = {Styles.CodeWrapper}
                    >
                        <code className={Styles.Code}>
                            {Text.join("\n")}
                        </code>
                    </pre>
                </div>
            </div>
        )
    }
}

export default ShowCode