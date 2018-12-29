import React from "react"
import * as Styles from "./Styles.css"

export default class AlgorithmVisualizer extends React.Component<{}, {}> {


    render () {

        return (
            <div id="FAB" className="fixed-action-btn">
                <a className="btn-floating btn-large red">
                    <i className="large material-icons">mode_edit</i>
                </a>
                <ul className={Styles.UnSelectable}>
                    <li>
                        <a 
                            className    = "btn-floating blue"
                            onClick      = {() => M.toast({html: 'Just click the code you want'})}>
                            <i className ="material-icons">content_copy</i>
                        </a>
                    </li>
                    <li>
                        <a 
                            className    = "btn-floating green darken-1"
                        >
                            <i className = "material-icons">code</i>
                        </a>
                    </li>
                </ul>
            </div>
        )
    }
}