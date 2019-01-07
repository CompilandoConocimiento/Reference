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
    theme: string,
}

export interface CodeActions {
}

interface CodeConfig {
    CodeStyles: CodeStyles,
    CodeActions: CodeActions
}

type Text = string[]

export interface FilePart        { name: string, parts: [number, number] }
export interface FilesDataResult { [index: string]: {[index: string]: Text} }
export interface FilesData       { [index: string]: FilePart[] }

export interface AlgorithmPageProps {
    filesData?: FilesDataResult,
}

export interface AlgorithmPageInformation {
    filesData: FilesData,
    CodeConfig: CodeConfig
}