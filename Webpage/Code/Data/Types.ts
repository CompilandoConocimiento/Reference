import React from "react"

interface NameLink { link: string, name: string }

interface AlgorithmData extends NameLink {
  Component: React.LazyExoticComponent<React.FunctionComponent>
}

interface TopicData extends NameLink {
  Algorithms: Array<AlgorithmData>
  linkToDirectoryCode: string
}

export { NameLink, AlgorithmData, TopicData }
