
import React from "react"
import { TopicData } from "../index"


const NumberTheoryData: TopicData = {
    name: "Number Theory",
    link: "NumberTheory",
    linkToDirectoryCode: "Code/NumberTheory/",
    Algorithms: [
        {
            name: "Binary Exponentiation",
            link: "BinaryExponentation",
            component: React.lazy(() => import('./BinaryExponentation'))
        }
        
    ]
}

export default NumberTheoryData 