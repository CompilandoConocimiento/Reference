import React from "react"
import Style from "./index.css"
import M from "materialize-css"
import { SubTopic, Topic } from "../Data/DataType"

function copyTextToClipboard(text: string): void {
    const textArea = document.createElement("textarea")
    textArea.value = text
    document.body.appendChild(textArea)
    textArea.focus()
    textArea.select()
    
    document.execCommand('copy')
    document.body.removeChild(textArea)
}

function areCommentsVisible(): boolean {
    const comment: HTMLElement = document.querySelector(".hljs-comment")
    if (comment == null) return false
    else return comment.style.display === "none"
}


type CodeHighlightType = {
    number: number,
    fontSize: number,
    text: string
}

const CodeHighlight: React.StatelessComponent<CodeHighlightType> = (props: CodeHighlightType) => {

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
                            className = {Style.CodeWrapper}
                        >
                            <code className={Style.Code}>
                                {props.text}
                            </code>
                        </pre>
                    </div>
                </div>
            </div>
        </div>
    )
}


type AlgorithmVisualizerType = {
    textArray: Array<string> | null,
    size: string,
}
type AlgorithmVisualizerProps = {
    Algorithm: SubTopic,
    Topic: Topic
}

export default class AlgorithmVisualizer extends React.Component<AlgorithmVisualizerProps, AlgorithmVisualizerType> {

    constructor(props) {
        super(props)

        this.state = {
            textArray: null, 
            size: props.Algorithm.Size,
        }
    }

    componentDidMount() {
        // @ts-ignore
        MathJax.Hub.Typeset()

        const elements = document.querySelectorAll("input[type=range]");
        M.Range.init(elements)

        const fab = document.querySelectorAll('.fixed-action-btn');
        M.FloatingActionButton.init(fab, {})

        let algorithmWebLink: string = "https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master"
        algorithmWebLink = `${algorithmWebLink}/Code/${this.props.Topic.link}/${this.props.Algorithm.file}`

        console.log(algorithmWebLink)
        fetch(algorithmWebLink)
            .then( 
                Data => { 
                    Data.text().then( 
                        (Text) => {
                            this.setState({textArray: Text.split("\n")}) 
                        }
                    )
                }
            )
    }

    componentDidUpdate () {
        this.props.Algorithm.visibleParts.forEach(
            // @ts-ignore
            (Element, Index) => hljs.highlightBlock( document.getElementById(`Code${Index}`) )
        )

    }

    toggleComments() {
        M.Toast.dismissAll()
        M.toast({html: 'Toggle comments'})

        document.querySelectorAll(".hljs-comment").forEach( (Element: HTMLElement) => {
            if (Element.style.display === "")
                Element.style.display = "initial"

            Element.style.display = (Element.style.display == "initial")? "none" : "initial"
        })
    }

    render () {

        return (
            <React.Fragment>
                
                {/* ================ TITLE ================================*/}
                <div className="row center blue-grey-text text-darken-3">
                    <h4>{this.props.Algorithm.name}</h4>
                </div>

                {/* ================ TEXT =================================*/}
                <div className="row">
                    <div className="col s10 offset-s1">
                        <div className={Style.Text}>
                            {this.props.Algorithm.text}
                        </div>
                    </div>
                </div>

                <br />
                <br />
                <br />
                
                {/* ================ SLIDER =================================*/}
                <div className="row">
                    <form className="col s12 m10 offset-m1 l10 offset-l1">
                        <p className="range-field">
                            <input 
                                type     = "range" 
                                min      = "0.3"
                                max      = "2.5"
                                step     = "0.035"
                                defaultValue = {this.state.size}
                                onChange = {e => this.setState({size: e.target.value})}
                            />
                        </p>
                    </form>
                </div>

                {/* ================ CODE ===================================*/}
                {
                    this.props.Algorithm.visibleParts.map(
                        (Range, Index) => (
                            <CodeHighlight 
                                key      = {Index}
                                number   = {Index} 
                                fontSize = {Number(this.state.size)}
                                text     = {
                                    (this.state.textArray == null)? 
                                        "Loading" : 
                                        this.state.textArray.slice(Range[0]-1, Range[1]+1).join("\n")
                                } 
                            />
                        )
                    )
                }
                {/* ================ FAB ====================================*/}
                <div className="fixed-action-btn">
                    <a className="btn-floating btn-large red">
                        <i className="large material-icons">mode_edit</i>
                    </a>
                    <ul className={Style.UnSelectable}>
                        <li>
                            <a 
                                className    = "btn-floating blue"
                                onClick      = {(e) => M.toast({html: 'Just click the code you want'})}>
                                <i className ="material-icons">content_copy</i>
                            </a>
                        </li>
                        <li>
                            <a 
                                className    = "btn-floating green darken-1"
                                onClick      = {this.toggleComments}>
                                <i className = "material-icons">code</i>
                            </a>
                        </li>
                    </ul>
                </div>

            </React.Fragment>
        )
    
    }
}