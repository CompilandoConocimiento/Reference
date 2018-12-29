import React from "react"
import * as Styles from "./Styles.css"

type CodeHighlightType = {
    number: number,
    fontSize: number,
    text: string
}


function copyTextToClipboard(text: string): void {
    const actualScroll = document.documentElement.scrollTop || document.body.scrollTop
    const textArea = document.createElement("textarea")
    textArea.value = text
    document.body.appendChild(textArea)
    textArea.focus()
    textArea.select()
    
    document.execCommand('copy')
    document.body.removeChild(textArea)
    scroll(0, actualScroll)
}

function areCommentsVisible(): boolean {
    const comment: HTMLElement = document.querySelector(".hljs-comment") as HTMLElement
    if (comment == null) return false
    else return comment.style.display === "none"
}



const CodeHighlight: React.FunctionComponent<CodeHighlightType> = (props: CodeHighlightType) => {

    function copyText(): void {
        const realText = areCommentsVisible()?
            props.text.split("\n").map( (line) => line.split("//")[0]).join("\n"):
            props.text
        
        copyTextToClipboard(realText)
        M.Toast.dismissAll()
        M.toast({html: 'Code copied ;)'})
    }

    if (props.text === "Loading") return (
        <div className="row">
            <div className="col s8 offset-s2">
                <div className="progress">
                    <div className="indeterminate"></div>
                </div>
            </div>
        </div>
    )

    return (
        <div className="row">
            <div className="col s12 m10 offset-m1 l10 offset-l1">
                <div className="card-panel hoverable" style={{backgroundColor: "#2b2b2b"}} onDoubleClick={copyText}>
                    <div className="row">
                        <pre id       = {`Code${props.number}`} 
                            style     = {{fontSize: `${props.fontSize}rem`}} 
                            className = {Styles.CodeWrapper}
                        >
                            <code className={Styles.Code}>
                                {props.text}
                            </code>
                        </pre>
                    </div>
                </div>
            </div>
        </div>
    )
}
