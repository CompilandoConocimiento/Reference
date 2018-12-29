import React from "react"
import M from "materialize-css"

import * as Styles from "./Styles.css"

import {  AlgorithmData, AlgorithmPageConfig, FilesDataResult } from "../../Data"
import { Loading } from "../Helpers"

// @ts-ignore
const updateMathJax = () => MathJax.Hub.Typeset()
const linkToBaseDirectoryToCode = "https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master"

interface AlgorithmVisualizerState {
    Component?: React.FunctionComponent,
    Config?: AlgorithmPageConfig,
    FilesDataResult?: FilesDataResult,
}

interface AlgorithmVisualizerProps { AlgorithmData: AlgorithmData, TopicLink: string }

export default class AlgorithmVisualizer extends React.Component<AlgorithmVisualizerProps, AlgorithmVisualizerState> {

    constructor(props: AlgorithmVisualizerProps) {
        super(props)
        this.state = {}
    }

    componentDidMount() {
        const FABNode = document.getElementById('FAB')!
        M.FloatingActionButton.init(FABNode, {})

        this.props.AlgorithmData.module()
            .then( Module => Module.default )
            .then( ({Config, Component}) => this.setState({Component, Config}, updateMathJax))
    }

    componentDidUpdate() {
        if (!this.state.FilesDataResult && this.state.Config) this.getCodeText()
    }

    getCodeText() {
        const baseLink = `${linkToBaseDirectoryToCode}/Code/${this.props.TopicLink}`
        const FilesDataResult: FilesDataResult = {}

        Object.entries(this.state.Config!.filesData).forEach( ([fileName, fileParts]) => {

            FilesDataResult[fileName] = []
            const codeLink = baseLink + "/" + fileName
            console.log(codeLink)
            
            fetch(codeLink)
                .then ( Data => Data.text()      )
                .then ( Text  => Text.split("\n") )
                .then ( Text  => {
                    fileParts.forEach( ([start, end]) => 
                        FilesDataResult[fileName].push(Text.slice(start, end + 1))
                    )

                    this.setState({FilesDataResult})
                    console.log(FilesDataResult)
                })

        })
    }

    

    //componentDidUpdate () {
    //    this.props.Algorithm.visibleParts.forEach(
    //        // @ts-ignore
    //        (Element, Index) => hljs.highlightBlock( document.getElementById(`Code${Index}`) )
    //    )
    //}
    

    toggleComments() {
        M.Toast.dismissAll()
        M.toast({html: 'Toggle comments'})
    
        document.querySelectorAll(".hljs-comment").forEach( (Element: any) => {
            if (Element.style.display === "")
                Element.style.display = "initial"
            Element.style.display = (Element.style.display == "initial")? "none" : "initial"
        })
    }

    render () {
        return (
            <React.Fragment>
                <div className="center blue-grey-text text-darken-3">
                    <h4>{this.props.AlgorithmData.name}</h4>
                </div>
                <br />

                <div className={"container " + Styles.Text}>
                    { this.state.Component?  <this.state.Component /> : <Loading /> }
                </div>

                <br />
                <br />
                <br />

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
                                onClick      = {() => this.toggleComments()}>
                                <i className = "material-icons">code</i>
                            </a>
                        </li>
                    </ul>
                </div>

            </React.Fragment>
        )
    
    }
}