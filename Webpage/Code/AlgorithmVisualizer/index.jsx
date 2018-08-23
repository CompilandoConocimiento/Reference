import React from "react"
import Style from "./index.css"

function CodeHighlight (props) {

    function fallbackCopyTextToClipboard(text) {
        const textArea = document.createElement("textarea")
        textArea.value = text
        document.body.appendChild(textArea)
        textArea.focus()
        textArea.select()
        
        const successful = document.execCommand('copy')
        
        document.body.removeChild(textArea)
    }

    function copyTextToClipboard(text) {
        if (!navigator.clipboard) {
            fallbackCopyTextToClipboard(text)
            return
        }
        navigator.clipboard.writeText(text)
    }

      
    function copyText() {

        copyTextToClipboard(props.text)
        
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
                <div className="card-panel hoverable" style={{backgroundColor: "#2b2b2b"}} onClick={copyText}>
                    <div className="row">
                        <pre id       = {`Code${props.Number}`} 
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
            <textarea readOnly style={{display: "none", margin: "-2rem", borderColor: "white", maxWidth: "0rem", maxHeight: "0rem", overflow: "hidden"}} id={`TextArea${props.Number}`} value={props.text} />
        </div>
    )
}

export default class AlgorithmVisualizer extends React.Component {

    constructor(props) {
        super(props)

        this.state = {
            TextArray: null, 
            Size: props.Algorithm.Size,
        }
    }

    componentDidMount() {
        MathJax.Hub.Typeset()

        const elements = document.querySelectorAll("input[type=range]");
        M.Range.init(elements)

        let algorithmWebLink = "https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master"
        algorithmWebLink = `${algorithmWebLink}/Code/${this.props.Topic.Link}/${this.props.Algorithm.File}`

        console.log(algorithmWebLink)
        fetch(algorithmWebLink)
            .then( Data => { Data.text().then( (Text) => this.setState({TextArray: Text.split("\n")}) ) } )
    }

    componentDidUpdate () {
        this.props.Algorithm.VisibleParts.forEach(
            (Element, Index) => hljs.highlightBlock( document.getElementById(`Code${Index}`) )
        )
    }

    render () {

        return (
            <React.Fragment>
                
                {/* ================ TITLE ================================*/}
                <div className="row center blue-grey-text text-darken-3">
                    <h4>{this.props.Algorithm.Name}</h4>
                </div>

                {/* ================ TEXT =================================*/}
                <div className="row">
                    <div className="col s10 offset-s1">
                        <div className={Style.Text}>
                            {this.props.Algorithm.Text}
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
                                value    = {this.state.Size}
                                onInput  = {e => this.setState({Size: e.target.value})}
                                onChange = {e => this.setState({Size: e.target.value})}
                            />
                        </p>
                    </form>
                </div>

                {/* ================ CODE ===================================*/}
                {
                    this.props.Algorithm.VisibleParts.map(
                        (Range, Index) => (
                            <CodeHighlight 
                                key      = {Index}
                                Number   = {Index} 
                                fontSize = {this.state.Size}
                                text     = {
                                    (this.state.TextArray == null)? 
                                        "Loading" : 
                                        this.state.TextArray.slice(Range[0]-1, Range[1]+1).join("\n")
                                } 
                            />
                        )
                    )
                }

            </React.Fragment>
        )
    
    }
}