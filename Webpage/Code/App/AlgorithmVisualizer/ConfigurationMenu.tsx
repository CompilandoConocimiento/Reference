import React from 'react'

import { AlgorithmPageInformation } from "../../Data"
import {loadTheme} from "./ShowCode"

interface ConfigurationMenuProps {
    setState: (newState: any, fn: any) => void, 
    Config: AlgorithmPageInformation
}

interface ConfigurationMenuState {
    Config: AlgorithmPageInformation
}

/**
   * A Modal that shows how to edit the Algorithms Page Information
   */
class ConfigurationMenu extends React.Component<ConfigurationMenuProps, ConfigurationMenuState> {
    
    constructor(props: ConfigurationMenuProps) {
        super(props)
        this.state = { Config: this.props.Config }
    }

    /**
     * Update all the fields that are necesary
     */
    componentDidMount() {
        const selects = document.querySelectorAll('select');
        M.FormSelect.init(selects, {});

        M.updateTextFields()
    }

    render () {

        return (
            <div id="modalConfig" className="modal">
                
                <div className="modal-content">
                    <h5>Configuration Menu</h5>
                    <ul style={{fontSize: "1.2rem", lineHeight: "3.5rem"}}>
                        <li>
                            Elevation: 
                            <div className="switch">
                                <label>
                                    Off
                                    <input 
                                        type     = "checkbox"
                                        checked  = {!(!this.state.Config.CodeConfig.CodeStyles.elevation)}
                                        onChange = { event => {
                                            let newValue = event.target.checked
                                            this.setState(preState => {
                                                const Config = preState.Config
                                                Config.CodeConfig.CodeStyles.elevation = newValue
                                                return {Config}
                                            })
                                        }}
                                    />
                                    <span className="lever"></span>
                                    On
                                </label>
                            </div>
                        </li>
                        <li>
                            FontSize: 
                            <div className="input-field">
                                <input 
                                    type     = "number" 
                                    style    = {{width: "fit-content"}}
                                    value    = {this.state.Config.CodeConfig.CodeStyles.fontSize.toString()} 
                                    onChange = { event => {
                                        let newValue = parseFloat(event.target.value)
                                        this.setState(preState => {
                                            const Config = preState.Config
                                            Config.CodeConfig.CodeStyles.fontSize = newValue
                                            return {Config}
                                        })
                                    }}
                                /> 
                            </div>
                        </li>
                        <li>
                            Theme: 
                            <div className="input-field col s12">
                                <select
                                    value     = {this.state.Config.CodeConfig.CodeStyles.theme} 
                                    style     = {{width: "fit-content"}}
                                    className = "browser-default"
                                    onChange  = { event => {
                                        const theme = event.target.value
                                        this.setState(preState => {
                                            const Config = preState.Config
                                            Config.CodeConfig.CodeStyles.theme = theme
                                            return {Config}
                                        })
                                    }}
                                >
                                    <option value="atom-one-dark">   Atom One Dark    </option>
                                    <option value="railscasts">      Railscasts       </option>
                                    <option value="agate">           Agate            </option>
                                    <option value="darcula">         Darcula          </option>
                                    <option value="zenburn">         Zenburn          </option>
                                    <option value="tomorrow">        Tomorrow         </option>
                                    <option value="gruvbox-dark">    Gruvbox Dark     </option>
                                    <option value="solarized-light"> Solarized Light  </option>
                                    <option value="hybrid">          Hybrid           </option>
                                </select>
                            </div>
                        </li>
                    </ul>
                </div>

                <div className="modal-footer">
                    <a 
                        className = "btn-flat"
                        onClick   = { () => {
                            loadTheme(this.state.Config.CodeConfig.CodeStyles.theme)
                            const codes = document.querySelectorAll("pre")
                            const updateCode = () => codes.forEach(code => window["hljs"].highlightBlock(code))
                            this.props.setState({Config: this.state.Config}, () => updateCode())
                        }}
                    >
                        Change
                    </a>
                    <a className="modal-close btn-flat">
                        Close
                    </a>
                </div>

            </div>
        )
    }
}

export default ConfigurationMenu