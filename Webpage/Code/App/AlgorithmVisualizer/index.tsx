import React from "react"
import M from "materialize-css"

import * as Styles from "./Styles.css"

import {  AlgorithmData, AlgorithmPageConfig, FilesDataResult } from "../../Data"
import { Loading } from "../Helpers"
import getCodeText from "./GetCodeText"
import FAB from "./FAB"


interface AlgorithmVisualizerProps { AlgorithmData: AlgorithmData, TopicLink: string }
interface AlgorithmVisualizerState {
    Component?: React.FunctionComponent,
    Config?: AlgorithmPageConfig,
    FilesDataResult?: FilesDataResult,
}

/**
   * This is a wrapper that helps to render the AlgorithmVisualizer.
   * 
   * @param AlgorithmData The data of the algorithm data
   * @param TopicLink The Topic.Link :v
   */
export default class AlgorithmVisualizer extends React.Component<AlgorithmVisualizerProps, AlgorithmVisualizerState> {

    constructor(props: AlgorithmVisualizerProps) {
        super(props)
        this.state = {}
    }

    componentDidMount() {
        const FABNode = document.getElementById('FAB')!, MathJax = () => window["MathJax"].Hub.Typeset()
        M.FloatingActionButton.init(FABNode, {})

        this.props.AlgorithmData.module()
            .then( Module => Module.default )
            .then( ({Config, Component}) => this.setState({Component, Config}, MathJax) )
    }

    componentDidUpdate() {
        if (!this.state.FilesDataResult && this.state.Config) 
            getCodeText(this.props.TopicLink, this.state.Config!.filesData, x => this.setState(x))
    }

    //componentDidUpdate () {
    //    this.props.Algorithm.visibleParts.forEach(
    //        // @ts-ignore
    //        (Element, Index) => hljs.highlightBlock( document.getElementById(`Code${Index}`) )
    //    )
    //}
    
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
                <br /><br /><br />

                <FAB />
            </React.Fragment>
        )
    }
}



const FABToDo = [
    () => {
        M.Toast.dismissAll()
        M.toast({html: 'Toggle comments'})
    
        document.querySelectorAll(".hljs-comment").forEach( (Element: any) => {
            if (Element.style.display === "")
                Element.style.display = "initial"
            Element.style.display = (Element.style.display == "initial")? "none" : "initial"
        })
    }
]

