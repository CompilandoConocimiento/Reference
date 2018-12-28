import React from "react"

export interface SubTopic {
    name: string
    link: string,
    file: string,
    visibleParts: Array<[number, number]>,
    size: number,
    text: JSX.Element,
}

export interface Topic {
    name: string,
    link: string,
    subTopics: Array<SubTopic>,
    baseLink: string
}
