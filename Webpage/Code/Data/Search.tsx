import React from "react"
import {SubTopic, Topic} from "./DataType"

const SubTopics: Array<SubTopic> = [
    {
        name: "Binary Search",
        link: "BinarySearch",
        file: "BinarySearch.cpp",
        visibleParts: [ [18, 32], [44, 58] ],
        size: 1.05,
        text: (
            <div>
                This is a search algorithm that work on monotonus functions \({`f(x)`}\).

                <br />

                You have a value \({`a`}\) and you want to find the \({`x`}\) such
                that \({`f(x)=a`}\) or to make sure such \({`x`}\) does not exist. 

                <br />

                This algorithm will execute in \({` O( \\log_2(n) ) `}\)

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
    {
        name: "Ternary Search",
        link: "TernarySearch",
        file: "TernarySearch.cpp",
        visibleParts: [ [14, 28] ],
        size: 1.05,
        text: (
            <div>

                This is just like the binary search, but, it does not just work in monotonus
                function, this is a search algorithm that work on unimodal functions \({`f(x)`}\).

                <br />

                This is used to find the minimum or maximum.

                <br />
                
                A ternary search determines either that the minimum or maximum cannot
                be in the first third of the domain or that it cannot be in the last
                third of the domain, then repeats on the remaining third.

            </div>
        ),
    },
    {
        name: "Lower and Upper Bound",
        link: "LowerAndUpperBound",
        file: "LowerAndUpperBound.cpp",
        visibleParts: [ [10, 22], [29, 41] ],
        size: 1.2,
        text: (
            <div>

                These are functions that are like brothers:
                <ul className="browser-default">
                    <li>
                        Lower bound return the index of the first item
                        in an ordered array that is not less that target
                    </li>
                    <li>
                        Upper bound return the index of the first item
                        in an ordered array that is greater that target
                    </li>
                </ul>

                Of course, both of them are almost identical in implementation
                and both are implemented using binary search.

            </div>
        ),
    }
]

const Search: Topic = {
    name: "Search",
    link: "Search",
    subTopics: SubTopics,
    baseLink: "Code/Search/"
}

export default Search