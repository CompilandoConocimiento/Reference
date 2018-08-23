import React from "react"
import Style from "./index.css"

function copyTextToClipboard(text) {
    if (!navigator.clipboard) {
        const textArea = document.createElement("textarea")
        textArea.value = text
        document.body.appendChild(textArea)
        textArea.focus()
        textArea.select()
        
        const successful = document.execCommand('copy')
        document.body.removeChild(textArea)
        return
    }
    navigator.clipboard.writeText(text)
}

function areCommentsVisible() {

    const comment = document.querySelector(".hljs-comment")
    if (comment == null) return false
    else return comment.style.display === "none"
}

function CodeHighlight (props) {

    function copyText() {
        const realText = areCommentsVisible()?
            props.text.split("\n").map( (e) => e.split("//")[0]).join("\n") : props.text
        
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

        const fab = document.querySelectorAll('.fixed-action-btn');
        M.FloatingActionButton.init(fab, {})

        let algorithmWebLink = "https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master"
        algorithmWebLink = `${algorithmWebLink}/Code/${this.props.Topic.Link}/${this.props.Algorithm.File}`

        console.log(algorithmWebLink)
        fetch(algorithmWebLink)
            .then( 
                Data => { 
                    Data.text().then( 
                        (Text) => {
                            this.setState({TextArray: Text.split("\n")}) 
                        }
                    )
                }
            )
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
                {/* ================ FAB ====================================*/}
                <div className="fixed-action-btn">
                    <a className="btn-floating btn-large red">
                        <i className="large material-icons">mode_edit</i>
                    </a>
                    <ul className={Style.UnSelectable}>
                        <li>
                            <a 
                                className="btn-floating blue"
                                onClick={(e) => M.toast({html: 'Just click the code you want'})}>
                                <i className="material-icons">content_copy</i>
                            </a>
                        </li>
                        <li>
                            <a 
                                className="btn-floating green darken-1"
                                onClick={
                                    (e) => {
                                        M.Toast.dismissAll()
                                        M.toast({html: 'Toggle comments'})
                                        const removeElements = (elms) => [...elms].forEach(el => {
                                            const actual = el.style.display
                                            if (actual === "") el.style.display = "initial"
                                            el.style.display = (el.style.display == "initial")? "none" : "initial"
                                        })

                                        removeElements( document.querySelectorAll(".hljs-comment") );
                                    }
                                }>
                                <i className="material-icons">code</i>
                            </a>
                        </li>
                    </ul>
                </div>

            </React.Fragment>
        )
    
    }
}