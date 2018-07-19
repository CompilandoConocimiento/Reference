// =====================================================================
// ============                 IMPORTS            =====================
// =====================================================================
import React from "react"
import {Data} from "./Data"
import './CoolCSS.css'

// =====================================================================
// ============                 CODE               =====================
// =====================================================================
export default class Code extends React.Component {

	constructor(props) {
        super(props)
        this.state = {
            Code: null,
            Size: 0.85,
            AlgorithmData: Data.Topics[props.TopicID].SubTopics.find( e => e.Link === this.props.match.params.Algorithm)
        }
	}

	componentDidMount() {
        const Elements = document.querySelectorAll('.fixed-action-btn')
        M.FloatingActionButton.init(Elements, {})

        fetch(`https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master/Code/${this.props.Topic}/${this.state.AlgorithmData.File}`)
        .then( Data => { Data.text().then( (Text) => this.setState({Code: Text}) ) } )
    }
    
    componentDidUpdate () {
        hljs.initHighlighting()
    }

	render () {
       
        return (
            <React.Fragment>
                <div className="row center blue-grey-text text-darken-3">
                    <h3>{this.state.AlgorithmData.Name}</h3>
                </div>

                <div className="row">
                    <div className="col s10 offset-s1">
                        <div className="card grey darken-1">
                            
                            <div className="card-content white-text">
                                
                                <span className="card-title">Hi</span>
                                
                                <p>Here a stupid text of {this.props.match.params.Algorithm} on the topic of {this.props.Topic}</p>
                            </div>
                        </div>
                    </div>
                </div>

                <div className="row">
                    <form className="col s8 offset-s2">
                        <p className="range-field">
                            <input 
                                type  = "range" 
                                min   = "0.2"
                                max   = "1.2"
                                step  = "0.05"
                                value = {this.state.Size}
                                onInput = {e => this.setState({Size: e.target.value})}
                                onChange = {e => this.setState({Size: e.target.value})}
                            />
                        </p>
                    </form>
                </div>

                <div className="row">
                    <div className="col s10 offset-s1">
                        <div className="card-panel hoverable ContainerHidden" style={{backgroundColor: "#333"}}>
                            <div className="row">
                                <br />
                                <pre style={{fontSize: `${this.state.Size}rem`}} className="ContainerHidden col s10 offset-s1">
                                    <code>
                                        {this.state.Code}
                                    </code>
                                </pre>
                            </div>
                        </div>
                    </div>
                </div>


            </React.Fragment>
        )
    
    }
}