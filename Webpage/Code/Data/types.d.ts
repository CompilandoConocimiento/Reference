import React from "react"

export interface NameLink {
    name: string;
    link: string;
}

export interface DirectoryTopic extends NameLink {
    subTopics: NameLink[];
}

export interface SubTopic extends NameLink {
    visibleParts: Array<[number, number]>,
    fileName: string,
    text: JSX.Element,
}

export interface Topic extends NameLink {
    subTopics: Array<SubTopic>,
    linkToDirectory: string
}

