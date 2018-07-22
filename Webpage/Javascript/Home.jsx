// =====================================================================
// ============                 IMPORTS            =====================
// =====================================================================
import React from "react"
import { Link } from 'react-router-dom'
import { Topics } from "./Data"

// =====================================================================
// ============                 HOME               =====================
// =====================================================================

function HelloCard (props) {

    const ButtonToPDF = (props) => (
        <a 
            href      = "https://compilandoconocimiento.github.io/Reference/Book/Reference.pdf" 
            target    = "_blank" 
            className = "waves-effect waves-teal amber hoverable lighten-4 btn-flat">
            GET THE PDF
        </a>
    )

    return (
        <div className="row">
            <div className="col s12">
                <div className="card" style={{backgroundColor: "#FFF8E1"}}>
                    <div className="card-content center blue-grey-text text-darken-3" style={{fontSize: "1.2rem"}}>
                        
                        <span className="card-title">
                            <b>Hi, Welcome to THE REFERENCE</b>
                        </span>
                        
                        <p>
                            This is a competitive reference, a repository of many of 
                            the algorithms that we have implemented to solve problems.

                            Enjoy, and remember with great code come great responsability.
                        </p> 
                        <br />

                        <p>
                            If you wish you can also check all this algorithms in a PDF
                            form, so you can use it in an ACM-ICPC competence.
                            
                        </p>
                        <br />

                        <ButtonToPDF />
                        <br />

                    </div>

                </div>
                
            </div>
        </div>
    )
}


function CardToTopic (props) {
    return (
        <div className="col s6">
            <div className={`card hoverable ${props.Color}`}>
                
                <div className="card-content white-text">
                    <span className="card-title">
                        {props.Name}
                    </span>
                </div>

                <div className="card-action">
                    <Link to={`/Topic/${props.Link}/`} className="white-text">
                        CHECK THE CODE
                    </Link>
                </div>

            </div>
        </div> 
    )

}

export default function Home (props) {

    const ColorsForCards = [
        "red lighten-2",
        "indigo lighten-2",
        "cyan lighten-1",
        "green lighten-2",
        "orange lighten-2",
        "brown lighten-2",
    ].sort(() => Math.random() - 0.5)

    let TopicsHTML = []
    for (let i = 0; i < Topics.length; i += 2) {
        let Topic1 = Topics[i], Topic2 = Topics[i+1]
        TopicsHTML.push(
            <div className="row" key={i}>
                <CardToTopic Color={ColorsForCards[i % ColorsForCards.length]} Name={Topic1.Name} Link={Topic1.Link}/>
                {
                    i + 1 != Topics.length && 
                    <CardToTopic Color={ColorsForCards[i+1 % ColorsForCards.length]} Name={Topic2.Name} Link={Topic2.Link}/>
                }
            </div>
        )
    }

    return (

        <div className="container">
            <HelloCard />
            {TopicsHTML}

            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />
            <br />

        </div>
    )
  
}