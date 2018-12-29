import React from "react"

export interface NameLink { name: string, link: string }

export type AlgorithmData = NameLink 

export interface TopicData extends NameLink {
    Algorithms: AlgorithmData[],
    linkToDirectoryCode: string,
}

export interface CodeStyles {
    size: string,
}

export interface CodeActions {

}

export interface FilesData { [index: string]: string[] }

export interface AlgorithmPageProps {
    filesData: FilesData
    codeProps: {
        codeStyles: CodeStyles
        codeActions: CodeActions
    }
}