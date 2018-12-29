import React from "react"
import M from "materialize-css"

import { AlgorithmPageProps }                      from "../../Data"
import { AlgorithmData, AlgorithmPageInformation } from "../../Data"
import { FilesDataResult }                         from "../../Data"
import { Loading }                                 from "../Helpers"
import getCodeText                                 from "./GetCodeText"
import FAB, {FABElement}                           from "./FAB"
import ConfigContext                               from "./ConfigContext"

import * as Styles from "./Styles.css"




interface VisualizerProps { AlgorithmData: AlgorithmData, TopicLink: string }
interface VisualizerState {
    Component?: React.FunctionComponent<AlgorithmPageProps>,
    Config?: AlgorithmPageInformation,
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
            getCodeText(this.props.TopicLink, this.state.Config!.filesData, code => this.setState(code))
    }
    
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
            },
            {
                color: "green",
                closeOnClick: true,
                icon: "arrow_upward",
                onClick: () => this.setState(preState => {
                    const newConfig = preState.Config
                    if (!newConfig) return null

                    newConfig.Config.CodeStyles.fontSize = newConfig.Config.CodeStyles.fontSize + 0.10
                    return {Config: newConfig}
                })
            },
            {
                color: "red",
                closeOnClick: true,
                icon: "arrow_downward",
                onClick: () => this.setState(preState => {
                    const newConfig = preState.Config
                    if (!newConfig) return null

                    newConfig.Config.CodeStyles.fontSize = newConfig.Config.CodeStyles.fontSize - 0.10
                    return {Config: newConfig}
                })
            },
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
                            <ConfigContext.Provider value={this.state.Config!.Config}>
                                <this.state.Component filesData = {this.state.FilesDataResult} />
                            </ConfigContext.Provider>
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