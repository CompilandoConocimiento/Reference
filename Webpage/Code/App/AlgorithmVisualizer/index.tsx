import React from "react"
import M from "materialize-css"

import { AlgorithmPageProps }                      from "../../Data"
import { AlgorithmData, AlgorithmPageInformation } from "../../Data"
import { FilesDataResult }                         from "../../Data"
import { Loading }                                 from "../Helpers"
import ConfigurationMenu                           from "./ConfigurationMenu"
import getCodeText                                 from "./GetCodeText"
import FAB, {FABElement}                           from "./FAB"
import ConfigContext                               from "./ConfigContext"

import * as Styles from "./Styles.css"

const linkToServer = "https://raw.githubusercontent.com/CompilandoConocimiento/Reference/master"

interface VisualizerProps { AlgorithmData: AlgorithmData, TopicLink: string }
interface VisualizerState {
    Component?: React.FunctionComponent<AlgorithmPageProps>,
    Config?: AlgorithmPageInformation,
    FilesDataResult?: FilesDataResult,
    Modal?: M.Modal,
    isLatexReady: boolean,
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
        this.state = { isLatexReady: false, }
    }

    /**
     * Load the module
     */
    componentDidMount() {
        this.props.AlgorithmData.module()
            .then( module => module.default )
            .then( moduleData => this.setState(moduleData) )
    }

    /**
     * This:
     * - Typeset LaTeX
     * - call getCodeText
     * - init the modal
     */
    componentDidUpdate() {

        if (!this.state.isLatexReady) {
            this.setState({isLatexReady: true}, () => window["MathJax"].Hub.Typeset())
        }
        else if (!this.state.FilesDataResult && this.state.Config) {
            const baseLink = `${linkToServer}/Code/${this.props.TopicLink}`
            const filesData = this.state.Config!.filesData
            getCodeText(baseLink, filesData, code => this.setState(code))
        }
        else if (!this.state.Modal) {
            const modalNode = document.querySelector('.modal')
            this.setState({Modal: M.Modal.init(modalNode!, {})})
        }
    }
    

    render () {
        
        const FABToDo: FABElement[] = [
            {
                color: "teal",
                closeOnClick: true,
                icon: "edit",
                onClick: () => this.state.Modal!.open(),
            },
            {
                color: "indigo",
                closeOnClick: false,
                icon: "code",
                onClick: () => {
                    M.Toast.dismissAll()
                    M.toast({html: 'Toggle comments'})
                
                    document.querySelectorAll(".hljs-comment").forEach( (comment: any) => {
                        if (comment.style.display === "") comment.style.display = "initial"
                        comment.style.display = (comment.style.display == "initial")? "none" : "initial"
                    })
                },
            },
            {
                color: "blue",
                closeOnClick: true,
                icon: "content_copy",
                onClick: () => M.toast({html: 'Just double click the code you want'})
            },
            {
                color: "green",
                closeOnClick: true,
                icon: "arrow_upward",
                onClick: () => this.setState(preState => {
                    const newConfig = preState.Config
                    if (!newConfig) return null

                    newConfig.CodeConfig.CodeStyles.fontSize = newConfig.CodeConfig.CodeStyles.fontSize + 0.10
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

                    newConfig.CodeConfig.CodeStyles.fontSize = newConfig.CodeConfig.CodeStyles.fontSize - 0.10
                    return {Config: newConfig}
                })
            },
        ]

        if (!this.state.Component || !this.state.Config) return <Loading />

        this.state.Config.CodeConfig.CodeStyles.fontSize

        return (
            <React.Fragment>
                
                <div className="center blue-grey-text text-darken-3">
                    <h4>{this.props.AlgorithmData.name}</h4>
                </div>
                <br />

                <div className={"container " + Styles.Text}>
                    <ConfigContext.Provider value={this.state.Config!.CodeConfig}>
                        <this.state.Component filesData = {this.state.FilesDataResult} />
                    </ConfigContext.Provider>
                </div>
                <br /><br /><br />

                <ConfigurationMenu 
                    setState = {(newState, fn) => this.setState(newState, fn)}
                    Config   = {this.state.Config!}
                />

                <FAB FABElements={FABToDo} />

            </React.Fragment>
        )
    }
}