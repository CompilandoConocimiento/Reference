/* ========= BASIC REACT THINGS ===============*/
import React from "react"

// =====================================================================
// ============             DYNAMIC PROGRAMMING       ==================
// =====================================================================

const SubTopics = [
    {
        Name: "Longest Common Subsequence",
        Link: "LongestCommonSubsequence",
        File: "LongestCommonSubsequence.cpp",
        VisibleParts: [ [9, 23] ],
        Size: 1,
        Text: (
            <div style={{fontSize: "1.1rem"}}>
                Let's recall the problem:
                Given two sequences, find the length of longest subsequence present in both of them.
                
                A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. 
                For example some subsequences of "abcdefg": 
                <ul className="browser-default">
                    <li>"abc"</li>
                    <li> "abg"</li>
                    <li> "bdf"</li>
                    <li> "aeg"</li>
                    <li> "acefg"</li>
                </ul>
                
                So a string of length \( n \) has \( 2^n \) different possible subsequences.

                So...Lets better find a better solution.

                <br />
                <br />

                The solution we present here is based in this function, suppose, X, Y are strings:
                <div style={{overflow: "auto"}}>
                $${`
                    f(X[0 : m], Y[0 : n]) = 
                    \\begin{cases}
                        1 + f(X[0 : m-1], Y[0 : n-1]  & \\text{if X[m] = Y[n]}  \\\\
                        max (f(X[0 : m], Y[0 : n-1], f(X[0 : m-1], Y[0 : n])  & \\text{if X[m] = Y[n]}  \\\\
                        0  & \\text{if m or n are 0} 
                    \\end{cases}
                `}$$
                </div>

                If you just want to see a animation of the problem you can
                click <a href="https://soyoscarrh.github.io/LCS/" target="_blank">here</a>
            </div>
        ),
    },
]

const DynamicProgramming = {
    Name: "Dynamic Programming",
    Link: "DynamicProgramming",
    SubTopics: SubTopics,
    BaseLink: "Code/DynamicProgramming/"
}

export default DynamicProgramming