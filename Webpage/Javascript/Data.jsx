/* ========= BASIC REACT THINGS ===============*/
import React from "react"
import './CoolCSS.css'

// =====================================================================
// ============               NUMBER THEORY        =====================
// =====================================================================
const NumberTheory = [
    {
        Name: "Sieve of Eratosthenes",
        Link: "SieveOfEratosthenes",
        File: "SieveOfEratosthenes.cpp",
        VisibleParts: [ [11, 23], [26, 45] ],
        Size: 1,
        Text: (
            <div style={{fontSize: "1.1rem"}}>
                The Sieve of Eratosthenes is a simple algorithm
                to find all the primes equal of smaller than n.
                
                It is given that \( n \leq 10^7 \).

                <br />
                <br />

                <h6><b>How it Works?</b></h6>
                <ol className="browser-default">
                    <li>
                        Suppose that all the numbers are prime
                    </li>
                    <li>
                        \( 0, 1 \) are not prime
                    </li>
                    <li>
                        For each number from \( 2 \) to \( n \) check if it is 
                        prime:
                        <ul className="browser-default">
                            <li>
                                If is prime: Delete all his multiples
                            </li>
                            <li>
                                If is not prime: Don't do anything
                            </li>
                        </ul>
                    </li>
                </ol>
                
                <h6><b>Optimizations</b></h6>

                One of the optimizations that we did here is that
                we avoid deleting many times the same numbers, for
                example the number \( 6 \) is going to be deleted
                by the \( 2 \) and the \( 3 \), so we start the multiples of \( i \)
                not in \( 2i \) but in \( i^2 \), because of this, we just need
                to check fewer numbers. 
            </div>
        ),
    },
    {
        Name: "Prime Factorization",
        Link: "PrimeFactorization",
        File: "PrimeFactorization.cpp",
        VisibleParts: [ [17, 32], [36, 49] ],
        Size: 0.95,
        Text: (
            <div style={{fontSize: "1.1rem"}}>

                The Prime Factorization algorithm presented here is just
                a simple modification of the Eratosthenes Sieve, so if you
                don't remember that Sieve, check it out.

                <br />
                <br />

                <h6><b>How it Works?</b></h6>
                <ol className="browser-default">
                    <li>
                        First, think of \( n \) into binary and check the number of \( 0's \),
                        that are at end of \( n \), lets call them \( x \) and eliminate from the number.
                        that means that the number can be divided by \( 2^x \) 

                        For Example \( 10100 \rightarrow 101 \)
                    </li>
                    <li>
                        After that \( n \) must be odd
                    </li>
                    <li>
                        Use a kind of sieve to find how many time does it divided for each odd number,
                        when you find a number that divide the new \( n \) divide the new \( n \) as many
                        times as it can.
                    </li>
                </ol>

                <br />
                <h6><b>Option B</b></h6>

                But, If you already have the vector of primes, don't complicate the things and just use
                the second code that I have give you.

            </div>
        ),
    },
    {
        Name: "Factorization of a Factorial",
        Link: "FactorizationOfFactorial",
        File: "FactorizationOfFactorial.cpp",
        VisibleParts: [ [10, 19], [21, 30] ],
        Size: 1.0,
        Text: (
            <div style={{fontSize: "1.1rem"}}>
                
                I asume that you know how to work with primes, if not
                check the Eratosthenes Sieve.

                This algorithm is really simple, as long as you know the 
                Legendre formula, just that, learn that.
            </div>
        ),
    },
]



// =====================================================================
// ============               STRING THEORY        =====================
// =====================================================================
const DynamicProgramming = [
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

export const Topics = [
    {
        Name: "Number Theory",
        Link: "NumberTheory",
        SubTopics: NumberTheory,
        BaseLink: "Code/NumberTheory/"
    },
    {
        Name: "Dynamic Programming",
        Link: "DynamicProgramming",
        SubTopics: DynamicProgramming,
        BaseLink: "Code/DynamicProgramming/"
    },
]
