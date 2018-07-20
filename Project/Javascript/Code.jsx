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

        const AlgorithmData = Data.Topics[props.TopicID].SubTopics.find( e => e.Link === this.props.match.params.Algorithm)
        this.state = {
            Code: null,
            AlgorithmData,
            Size: AlgorithmData.Size,
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
        console.log("hi")
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
                                step  = "0.075"
                                value = {this.state.Size}
                                onInput = {e => this.setState({Size: e.target.value})}
                                onChange = {e => this.setState({Size: e.target.value})}
                            />
                        </p>
                    </form>
                </div>

                <div className="row">
                    <div className="col s12 m10 offset-m1 l10 offset-l1">
                        <div className="card-panel hoverable ContainerHidden" style={{backgroundColor: "#474949"}}>
                            <div className="row">
                                <pre style={{fontSize: `${this.state.Size}rem`}} className="ContainerHidden col s12">
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