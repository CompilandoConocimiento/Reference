import React from "react"
import {SubTopic, Topic} from "./DataType"

const SubTopics: Array<SubTopic> = [
    {
        name: "Trie",
        link: "Trie",
        file: "Trie.cpp",
        visibleParts: [ [6, 32] ],
        size: 1.10,
        text: (
            <div>
                This is a very basic and famous data structure for string \({`f(x)`}\).

                This is a tree where each node represent a node (and a little flag to tell 
                if this is a final word).
            </div>
        ),
    },
]

const Strings: Topic = {
    name: "Strings",
    link: "Strings",
    subTopics: SubTopics,
    baseLink: "Code/Strings/"
}

export default Strings