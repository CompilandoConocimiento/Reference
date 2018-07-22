// =====================================================================
// ============                 IMPORTS            =====================
// =====================================================================
import React from "react"
import {Data} from "./Data"
import './CoolCSS.css'

// =====================================================================
// ============                 CODE               =====================
// =====================================================================

function CodeHighlight (props) {

    if (props.Code === "Loading") return (
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
                <div className="card-panel hoverable" style={{backgroundColor: "#2b2b2b"}}>
                    <div className="row">
                        <pre id={`Code${props.Number}`} 
                            style={{fontSize: `${props.Size}rem`}} 
                            className="ContainerHidden col s12">
                            <code>
                                {props.Code}
                            </code>
                        </pre>
                    </div>
                </div>
            </div>

            <br />
            <br />

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

        let AlgorithmWebLink = "https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master"
        AlgorithmWebLink = `${AlgorithmWebLink}/Code/${this.props.Topic.Link}/${this.props.Algorithm.File}`

        fetch(AlgorithmWebLink)
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
                
                <div className="row center blue-grey-text text-darken-3">
                    <h4>{this.props.Algorithm.Name}</h4>
                </div>

                <div className="row">
                    <div className="col s10 offset-s1">
                        {this.props.Algorithm.Text}
                        <br /><br /><br />
                    </div>
                </div>

                <div className="row">
                    <form className="col s12 m10 offset-m1 l10 offset-l1">
                        <p className="range-field">
                            <input 
                                type  = "range" 
                                min   = "0.2"
                                max   = "2"
                                step  = "0.035"
                                value = {this.state.Size}
                                onInput = {e => this.setState({Size: e.target.value})}
                                onChange = {e => this.setState({Size: e.target.value})}
                            />
                        </p>
                    </form>
                </div>

                {
                    this.props.Algorithm.VisibleParts.map(
                        (Range, Index) => (
                            <CodeHighlight 
                                key    = {Index}
                                Number = {Index} 
                                Size   = {this.state.Size}
                                Code   = {
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