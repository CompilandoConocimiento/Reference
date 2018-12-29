import React from "react"
import { FilesDataResult } from "../../Data"

import { copyText }  from "./CodeActions"
import ConfigContext from "./ConfigContext"
import * as Styles   from "./Styles.css"

enum CodeStatus { Loading, WaitingBlockUpdate, Ready }
interface CodeState {codeMonted: CodeStatus}
interface CodeProps {
    ID: string,
    Data: FilesDataResult | undefined,
    fileName: string,
    partOfFile: number,
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
            <div className="card-panel hoverable" 
                style={{backgroundColor: "#2b2b2b", padding: "8px"}}
                onDoubleClick={() => copyText(Text)}>
                <ConfigContext.Consumer>
                    {
                        Config => (
                            <pre id       = {this.props.ID} 
                                style     = {{fontSize: `${Config.CodeStyles.fontSize}rem`}} 
                                className = {Styles.CodeWrapper}>
                                <code className={Styles.Code}>
                                    {Text.join("\n")}
                                </code>
                            </pre>
                        )
                    }
                </ConfigContext.Consumer>
            </div>
        )
    }
}

export default ShowCode