import React from "react"

import { CodeConfig } from "../../Data"

const PageConfig: CodeConfig = {
    CodeActions: {
    },
    CodeStyles: { 
        backgroundColor: "", 
        fontSize: 0.8,
    },
}

const ConfigContext = React.createContext(PageConfig)

export default ConfigContext