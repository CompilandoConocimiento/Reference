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
    backgroundColor: string,
}

export interface CodeActions {
}

interface CodeConfig {
    CodeStyles: CodeStyles,
    CodeActions: CodeActions
}

type Text = string[]

export interface FilesDataResult { [index: string]: Text[] }
export interface FilesData       { [index: string]: [number, number][] }

export interface AlgorithmPageProps {
    filesData?: FilesDataResult,
}

export interface AlgorithmPageInformation {
    filesData: FilesData,
    CodeConfig: CodeConfig
}