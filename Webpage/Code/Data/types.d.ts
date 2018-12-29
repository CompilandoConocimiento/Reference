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

export interface PageConfig {
}

interface AlgorithmPageConfig {
    CodeStyles: CodeStyles,
    CodeActions: CodeActions
    PageConfig: PageConfig
}

type Text = string[]

export interface FilesDataResult { [index: string]: Text[] }
export interface FilesData       { [index: string]: [number, number][] }

export interface AlgorithmPageProps {
    filesData?: FilesDataResult,
}

export interface AlgorithmPageInformation {
    filesData: FilesData,
    Config: AlgorithmPageConfig
}