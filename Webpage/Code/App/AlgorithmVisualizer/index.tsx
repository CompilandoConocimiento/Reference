import React from "react"
import M from "materialize-css"

import {  AlgorithmData, AlgorithmPageConfig, AlgorithmPageProps, FilesDataResult } from "../../Data"
import { Loading } from "../Helpers"
import getCodeText from "./GetCodeText"
import FAB, {FABElement} from "./FAB"

import * as Styles from "./Styles.css"

interface VisualizerProps { AlgorithmData: AlgorithmData, TopicLink: string }
interface VisualizerState {
    Component?: React.FunctionComponent<AlgorithmPageProps>,
    Config?: AlgorithmPageConfig,
    FilesDataResult?: FilesDataResult,
}

/**
   * This is a wrapper that helps to render the AlgorithmVisualizer.
   * 
   * @param AlgorithmData The data of the algorithm data
   * @param TopicLink The Topic.Link :v
   */
export default class AlgorithmVisualizer extends React.Component<VisualizerProps, VisualizerState> {

    constructor(props: VisualizerProps) {
        super(props)
        this.state = {}
    }

    componentDidMount() {
        const MathJax = () => window["MathJax"].Hub.Typeset()

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

        const FABToDo: FABElement[] = [
            {
                color: "green darken-1",
                closeOnClick: false,
                icon: "code",
                onClick: () => {
                    M.Toast.dismissAll()
                    M.toast({html: 'Toggle comments'})
                
                    document.querySelectorAll(".hljs-comment").forEach( (Element: any) => {
                        if (Element.style.display === "")
                            Element.style.display = "initial"
                        Element.style.display = (Element.style.display == "initial")? "none" : "initial"
                    })
                },
            },
            {
                color: "blue",
                closeOnClick: true,
                icon: "content_copy",
                onClick: () => M.toast({html: 'Just click the code you want'})
            }
        ]

        return (
            <React.Fragment>
                <div className="center blue-grey-text text-darken-3">
                    <h4>{this.props.AlgorithmData.name}</h4>
                </div>
                <br />

                <div className={"container " + Styles.Text}>
                    {
                        this.state.Component? 
                            <this.state.Component 
                                codeProps = {this.state.Config!.codeProps} 
                                filesData = {this.state.FilesDataResult}
                            />
                        :
                            <Loading />
                    }
                </div>
                <br /><br /><br />

                <FAB FABElements={FABToDo} />
            </React.Fragment>
        )
    }
}