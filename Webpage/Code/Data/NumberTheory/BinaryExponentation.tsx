import React from "react"
import { AlgorithmPageProps, AlgorithmPageInformation } from "../index"
import ShowCode from "../../App/AlgorithmVisualizer/ShowCode"
import { LaTeX } from "../../App/AlgorithmVisualizer/LaTeX"

const PageConfig: AlgorithmPageInformation = {
    filesData: {
        "BinaryExponentiation.cpp": [
            {name: "RecursiveBinExpo", parts: [1, 8] }, 
            {name: "SimpleBinExpo", parts: [10, 25] }, 
            {name: "BinExpo", parts: [27, 39] }, 
            {name: "ModularBinExpo", parts: [41, 54] }, 
        ]
    },
    CodeConfig: {
        CodeStyles: { fontSize: 0.9, theme: "" },
        CodeActions: {},
    }
}

const BinaryExponentation: React.FunctionComponent<AlgorithmPageProps> = ({filesData}) => {
    return (
        <div>

            <h5><b>Definition</b></h5>

                This function will performe \( {"base^{exponent}"} \) but a little bit more fast using
                exponentiation by squaring.
                The idea is to see this way of expressing exponentiation:
                <LaTeX>
                    {String.raw`
                        base ^ {exponent} = 
                        \begin{cases}
                        (base^2)^{\; \frac{exponent}{2}}             & \text{if exponent is even}  \\
                        base \; (base^2)^{\; \frac{exponent-1}{2}}   & \text{if exponent is odd}   \\
                        \end{cases}
                    `}  
                </LaTeX>

                Or if you like small variable names we can say that \( base = x \) y \( exponent = n \):
                <LaTeX>
                    {String.raw`
                        x^n = 
                        \begin{cases}
                        (x^2)^{\; \frac{n}{2}}           & \text{if n is even}  \\
                        x \; (x^2)^{\; \frac{n-1}{2}}    & \text{if n is odd}   \\
                        \end{cases}
                    `}  
                </LaTeX>

                <ShowCode 
                    Data       = {filesData}
                    fileName   = {"BinaryExponentiation.cpp"}
                    partOfFile = {"RecursiveBinExpo"}
                />
                <br />

            <h5><b>Simple Optimizations</b></h5>

            Now we want to eliminate the recursion and modify a little bit the idea:
                <ul className="browser-default">
                    <li>
                        If exponent is odd, first do \( {"solution = base * solution"} \),
                        now, we have to delete 1 to the exponent, so the exponent is even, so
                        we can just say that the base is \( {"base = base^2"} \) and that the
                        exponent is just the half of the original exponent.
                    </li>
                    <li>
                        If exponent is even, so
                        we can just say that the base is \( {"base = base^2"} \) and that the
                        exponent is just the half of the original exponent.
                    </li>
                </ul>

                <ShowCode 
                    Data       = {filesData}
                    fileName   = {"BinaryExponentiation.cpp"}
                    partOfFile = {"SimpleBinExpo"}
                />
                <br />
            

            <h5><b>Optimizations</b></h5>

                <h6><b>How to optimize \( {"e = \\frac{e-1}{2} "} \) and \( {"e = \\frac{e}{2} "} \) </b></h6>

                Remember the bitwise operations equalities:
                <ul className="browser-default">
                    <li> { "\\( x << y = x * 2^y \\)" } </li>
                    <li> { "\\( x >> y = \\left \\lfloor \\dfrac{x}{2^y} \\right \\rfloor \\)" } </li>
                </ul>

                This optimizations are using the bitwise operations.
                I claim that 
                \( {"e = \\frac{e-1}{2} "} \) and \( {"e = \\frac{e}{2} "}\) are equal to
                \( {"e = e >> 1"}\).

                <br />
                <br />

                This is easy to proof, because \( {"e = e >> 1"}\) delete the least significant bit,
                so the last bit does not really matter. 
                So you find that at the end it does not matter if it is odd or even
                this will always give you the correct answer.

                <br />
                <br />

                <h6><b>Check in the exponent is odd or even</b></h6>

                To do this just do exponent & 1
                <br />
                    
                For example the number \(000101101010\) if the exponent 
                was odd then the last digit will be 1, so exponent & 1
                give true only if the last digit was 1.

                <ShowCode 
                    Data       = {filesData}
                    fileName   = {"BinaryExponentiation.cpp"}
                    partOfFile = {"BinExpo"}
                />
                <br />

            <h5><b>Modular Exponentation</b></h5>

                This is to do \( {"base^{exponent}\\mod n"}\)

                <ShowCode 
                    Data       = {filesData}
                    fileName   = {"BinaryExponentiation.cpp"}
                    partOfFile = {"ModularBinExpo"}
                />

        </div>
    )
} 

export default { Config: PageConfig, Component: BinaryExponentation }