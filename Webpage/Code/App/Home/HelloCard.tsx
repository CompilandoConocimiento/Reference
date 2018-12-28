import React from "react"

const HelloCard: React.FunctionComponent<{radius: string}> = props => (
    <div 
        className = "card-panel center blue-grey-text text-darken-3"
        style     = {{
            borderRadius: `${props.radius} ${props.radius} ${props.radius} ${props.radius}`,
            backgroundColor: "#FFF8E1", 
            fontSize: "1.2rem", 
        }}>
            
        <h5 style={{fontWeight: 300}}>
            Hi, Welcome to THE REFERENCE
        </h5>
        
        <p>
            This is a competitive reference, a repository of many of 
            the algorithms that we have implemented to solve problems.

            Enjoy, and remember with great code come great responsability.
        </p> 

        <p>
            If you wish you can also check all this algorithms in a PDF
            form, so you can use it in an ACM-ICPC competence.
        </p>

        <a 
            href      = "https://compilandoconocimiento.github.io/Reference/Books/Reference/" 
            target    = "_blank" 
            className = "btn-flat waves-effect amber lighten-4">
            GET THE PDF
        </a>

        <br />

    </div>
)

export default HelloCard