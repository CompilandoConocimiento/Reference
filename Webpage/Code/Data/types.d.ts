import React from "react"

export interface NameLink { name: string, link: string }

export interface AlgorithmData extends NameLink {
    module: () => Promise<any>,
} 

export interface TopicData extends NameLink {
    Algorithms: AlgorithmData[],
    linkToDirectoryCode: string,
}

export interface CodeStyles {
    fontSize: number,
}

export interface CodeActions {
}

type Text = string[]

export interface FilesDataResult { [index: string]: Text[] }
export interface FilesData       { [index: string]: [number, number][] }

export interface AlgorithmPageProps {
    filesData?: FilesDataResult,
    codeProps: {
        codeStyles: CodeStyles,
        codeActions: CodeActions
    }
}

export interface AlgorithmPageConfig {
    filesData: FilesData,
    codeProps: {
        codeStyles: CodeStyles,
        codeActions: CodeActions
    }
}