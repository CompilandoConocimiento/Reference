import React from "react"

const SubTopics = [
    {
        Name: "Binary Search",
        Link: "BinarySearch",
        File: "BinarySearch.cpp",
        VisibleParts: [ [16, 30] ],
        Size: 1.05,
        Text: (
            <div>
                This is a search algorithm that work on monotonus functions.
                Not just to search in an ordered array, rememeber that.

                If will find an item in  \({` O( \\log_2(n) ) `}\)

                <h6><b>How it Works?</b></h6>
                <ol className="browser-default">
                    <li>
                        Select the middle point in your search range
                    </li>
                    <li>
                        Is the item you are looking for there?
                        <ul className="browser-default">
                            <li>
                                If yes: Finish :)
                            </li>
                            <li>
                                If not
                                <ul className="browser-default">
                                    <li>
                                        If the item you found is bigger
                                        then search in the left part of the range 
                                    </li>
                                    <li>
                                        If the item you found is smaller
                                        then search in the right part of the range 
                                    </li>
                                </ul>
                            </li>
                        </ul>
                    </li>
                </ol>
                
                <h6><b>Optimizations</b></h6>

                Just use while loop instead of recursive calls.

            </div>
        ),
    },
]

const Search = {
    Name: "Search",
    Link: "Search",
    SubTopics: SubTopics,
    BaseLink: "Code/Search/"
}

export default Search