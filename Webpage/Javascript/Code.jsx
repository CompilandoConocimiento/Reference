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

export default class Code extends React.Component {

	constructor(props) {
        super(props)

        const AlgorithmData = Data.Topics[props.TopicID].SubTopics.find( e => e.Link === this.props.match.params.Algorithm)
        this.state = {
            AlgorithmData,
            TextArray: null, 
            Size: AlgorithmData.Size,
        }
	}

	componentDidMount() {
        const Elements = document.querySelectorAll('.fixed-action-btn')
        M.FloatingActionButton.init(Elements, {})
        MathJax.Hub.Typeset()

        fetch(`https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master/Code/${this.props.Topic}/${this.state.AlgorithmData.File}`)
        .then( Data => { Data.text().then( (Text) => this.setState({TextArray: Text.split("\n")}) ) } )
    }

    
    
    componentDidUpdate () {

        this.state.AlgorithmData.VisibleParts.forEach(
            (Element, Index) => {
                let Code = document.getElementById(`Code${Index}`)
                hljs.highlightBlock(Code)
            }
        )

    }

	render () {
       
        return (
            <React.Fragment>
                <div className="row center blue-grey-text text-darken-3">
                    <h4>{this.state.AlgorithmData.Name}</h4>
                </div>

                <div className="row">
                    <div className="col s10 offset-s1">
                        {this.state.AlgorithmData.Text}
                        <br />
                        <br />
                        <br />
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
                    this.state.AlgorithmData.VisibleParts.map(
                        (Range, Index) => (
                            <CodeHighlight 
                                key    = {Index}
                                Number = {Index} 
                                Size   = {this.state.Size}
                                Code   = {(this.state.TextArray == null)? "Loading" : this.state.TextArray.slice(Range[0]-1, Range[1]+1).join("\n")} 
                            />
                        )
                    )
                }


            </React.Fragment>
        )
    
    }
}