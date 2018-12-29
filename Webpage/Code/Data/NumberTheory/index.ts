import { TopicData } from "../types"

const NumberTheoryData: TopicData = {
    name: "Number Theory",
    link: "NumberTheory",
    linkToDirectoryCode: "Code/NumberTheory/",
    Algorithms: [
        {
            name: "Binary Exponentiation",
            link: "BinaryExponentation",
            module: () => import("./BinaryExponentation"),
        }
        
    ]
}

export default NumberTheoryData 