import React from "react"
import {SubTopic, Topic} from "./DataType"

const SubTopics: Array<SubTopic> = [
    {
        name: "Sieve of Eratosthenes",
        link: "SieveOfEratosthenes",
        file: "SieveOfEratosthenes.cpp",
        visibleParts: [ [8, 22], [25, 42] ],
        size: 1.05,
        text: (
            <div>
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

                <br />
                <br />

                Also we jump 2 numbers at a time.
                
            </div>
        ),
    },
    {
        name: "Prime Factorization",
        link: "PrimeFactorization",
        file: "PrimeFactorization.cpp",
        visibleParts: [ [18, 35], [39, 53] ],
        size: 0.95,
        text: (
            <div>

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

                <br />
                <h6><b>What does this return</b></h6>

                This functions return a vector, where each element is a pair integers of the 
                form \( {`\\{p_n, e_n \\}`} \), so you could read the return data as:

                <div style={{overflow: "auto"}}>
                $${`
                    PrimeFactorization(n)
                        = \\prod_{i = 1}^{n} p_i^{e_i}
                        = (p_1^{e_1}) (p_2^{e_2}) (p_3^{e_3}) \\dots (p_n^{e_n})
                `}$$
                </div>

            </div>
        ),
    },
    {
        name: "Binary Exponentiation",
        link: "BinaryExponentiation",
        file: "BinaryExponentiation.cpp",
        visibleParts: [ [9, 20], [22, 30], [33, 45], ],
        size: 0.95,
        text: (
            <div>
                This function will performe \( {"base^{exponent}"} \) but a little bit more fast using
                exponentiation by squaring.

                <div style={{overflow: "auto"}}>
                $${`
                    base ^ {exponent} = 
                    \\begin{cases}
                        base \\; (base^2)^{\\; \\frac{exponent-1}{2}}   & \\text{if exponent is odd}   \\\\
                        (base^2)^{\\; \\frac{exponent}{2}}          & \\text{if exponent is even}  \\\\
                    \\end{cases}
                `}$$
                </div>

                Or if you like small variable names we can say that \( base = x \) y \( exponent = n \):
                <div style={{overflow: "auto"}}>
                $${`
                    x^n = 
                    \\begin{cases}
                        x \\; (x^2)^{\\; \\frac{n-1}{2}}    & \\text{if n is odd}   \\\\
                        (x^2)^{\\; \\frac{n}{2}}            & \\text{if n is even}  \\\\
                    \\end{cases}
                `}$$
                </div>

                Remember the bitwise operations equalities:
                <ul className="browser-default">
                    <li> { "\\( x << y = x * 2^y \\)" } </li>
                    <li> { "\\( x >> y = \\left \\lfloor \\dfrac{x}{2^y} \\right \\rfloor \\)" } </li>
                </ul>

                <br />
                <h6><b>How to optimize \( {"e = \\frac{e-1}{2} "} \) and \( {"e = \\frac{e}{2} "}\) </b></h6>

                This optimizations are using the bitwise operations.
                I claim that \( {"e = \\frac{e-1}{2} "} \) and \( {"e = \\frac{e}{2} "}\) are equal to
                \( {"e = e >> 1"}\).

                <br />
                <br />

                This is easy to proof, because \( {"e = e >> 1"}\) delete the least significant bit,
                so the last bit does not really matter. 
                So you find that at the end it does not matter if it is odd or even
                this will always give you the correct answer

                <br />
                <br />

                <h6><b>Check in the exponent is odd or even</b></h6>

                To do this just do exponent & 1
                <br />
                  
                For example the number \(000101101010\) if the exponent 
                was odd then the last digit will be 1, so exponent & 1
                give true only if the last digit was 1.

            </div>
        ),
    },
]

const NumberTheory: Topic = {
    name: "Number Theory",
    link: "NumberTheory",
    subTopics: SubTopics,
    baseLink: "Code/NumberTheory/"
}

export default NumberTheory