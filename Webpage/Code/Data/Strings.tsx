import React from "react"

const SubTopics = [
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

const Strings = {
    name: "Strings",
    link: "Strings",
    subTopics: SubTopics,
    baseLink: "Code/Strings/"
}

export default Strings