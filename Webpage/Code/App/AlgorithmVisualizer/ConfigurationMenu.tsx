import React from 'react'

import { AlgorithmPageInformation } from "../../Data"

interface ConfigurationMenuProps {
    setState: (newState: any) => void, 
    Config: AlgorithmPageInformation
}

interface ConfigurationMenuState {
    Config: AlgorithmPageInformation
}


class ConfigurationMenu extends React.Component<ConfigurationMenuProps, ConfigurationMenuState> {
    
    constructor(props: ConfigurationMenuProps) {
        super(props)
        this.state = { Config: this.props.Config }
    }

    componentDidMount() {
        M.updateTextFields()
    }

    render () {
        return (
            <div id="modalConfig" className="modal">
                
                <div className="modal-content">
                    <h5>Configuration Menu</h5>
                    <ul style={{fontSize: "1.2rem", lineHeight: "3.5rem"}}>
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
                                <label htmlFor="first_name">Font Size</label>
                            </div>
                        </li>
                        <li>
                            Background: 
                        </li>
                    </ul>
                </div>

                <div className="modal-footer">
                    <a 
                        className = "btn-flat"
                        onClick   = { () => this.props.setState({Config: this.state.Config})}
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