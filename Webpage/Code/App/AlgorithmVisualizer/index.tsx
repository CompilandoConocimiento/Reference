import React from "react"
import * as Styles from "./Styles.css"

import M from "materialize-css"
import { FilesData, CodeStyles, CodeActions, AlgorithmData } from "../../Data"

const linkToBaseDirectoryToCode = "https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master"


interface AlgorithmVisualizerState {
    FilesData: FilesData | null,
    CodeProps: { CodeStyles: CodeStyles, CodeActions: CodeActions }
    AlgorithmComponent: any
}

interface AlgorithmVisualizerProps { AlgorithmData: AlgorithmData, TopicLink: string }

export default class AlgorithmVisualizer extends React.Component<AlgorithmVisualizerProps, AlgorithmVisualizerState> {

    constructor(props: AlgorithmVisualizerProps) {
        super(props)
        this.state = { 
            CodeProps: {CodeStyles: { size:"1.15" }, CodeActions: {}}, 
            FilesData: null, 
            AlgorithmComponent: null 
        }
    }

    componentDidMount() {
        // @ts-ignore
        MathJax.Hub.Typeset()

        const FABNode = document.getElementById('FAB')!
        M.FloatingActionButton.init(FABNode, {})

        const baseLink = `${linkToBaseDirectoryToCode}/Code/${this.props.TopicLink}`

        //this.props.AlgorithmData.fileNames.forEach()
        //const algorithmWebLink = `${baseLink}/${this.props.AlgorithmData.fileNames[0]}`
        //
        //console.log(algorithmWebLink)
        //fetch(algorithmWebLink)
        //    .then( 
        //        Data => { 
        //            Data.text().then( 
        //                (Text) => {
        //                    this.setState({textArray: Text.split("\n")}) 
        //                }
        //            )
        //        }
        //    )
    }

    //componentDidUpdate () {
    //    this.props.Algorithm.visibleParts.forEach(
    //        // @ts-ignore
    //        (Element, Index) => hljs.highlightBlock( document.getElementById(`Code${Index}`) )
    //    )
    //}

    //toggleComments() {
    //    M.Toast.dismissAll()
    //    M.toast({html: 'Toggle comments'})
    //
    //    document.querySelectorAll(".hljs-comment").forEach( (Element: any) => {
    //        if (Element.style.display === "")
    //            Element.style.display = "initial"
    //        Element.style.display = (Element.style.display == "initial")? "none" : "initial"
    //    })
    //}

    render () {

        return (
            <React.Fragment>
                
                {/* ================ TITLE ================================*/}
                <div className="row center blue-grey-text text-darken-3">
                    <h4>{this.props.AlgorithmData.name}</h4>
                </div>

                {/* ================ TEXT =================================*/}
                <div className="row">
                    <div className="col s10 offset-s1">
                        <div className={Styles.Text}>
                            {this.state.AlgorithmComponent}
                        </div>
                    </div>
                </div>

                <br />
                <br />
                <br />

                {/* ================ FAB ====================================*/}
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
                                className    = "btn-floating green darken-1">
                                <i className = "material-icons">code</i>
                            </a>
                        </li>
                    </ul>
                </div>

            </React.Fragment>
        )
    
    }
}