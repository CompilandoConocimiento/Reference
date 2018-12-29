import React from "react"
import { AlgorithmPageConfig } from "../../Data"

const PageConfig: AlgorithmPageConfig = {
    CodeActions: {},
    CodeStyles: { fontSize: 0.8 },
    PageConfig: {}
}

const ConfigContext = React.createContext(PageConfig)

export default ConfigContext