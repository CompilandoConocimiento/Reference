import React from "react"
import { TopicData } from "../Types"

const NumberTheoryData: TopicData = {
  name: "Number Theory",
  link: "NumberTheory",
  linkToDirectoryCode: "Code/NumberTheory/",
  Algorithms: [
    {
      name: "Binary Exponentiation",
      link: "BinaryExponentation",
      Component: React.lazy(() => import("./BinaryExponentation")),
    },
  ],
}

export default NumberTheoryData
