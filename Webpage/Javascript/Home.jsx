// =====================================================================
// ============                 IMPORTS            =====================
// =====================================================================
import React from "react"
import { Link } from 'react-router-dom'
import {Data} from "./Data"

// =====================================================================
// ============                 HOME               =====================
// =====================================================================
export default function Home (props) {

    const ColorsForCards = [
        "red lighten-2",
        "indigo lighten-2",
        "cyan lighten-1",
        "green lighten-2",
        "orange lighten-2",
        "brown lighten-2",
    ].sort(() => Math.random() - 0.5)


    const Topics = Data.MiniData.map(e => e[0])
    const TopicsHTML = []
    for (let i = 0; i < Topics.length; i += 2) {

        const Card1 = (
            <div className="col s6">
                <div className={`card hoverable ${ColorsForCards[i % ColorsForCards.length]}`}>
                    <div className="card-content white-text">
                        <span className="card-title">{Topics[i][0]}</span>
                    </div>
                    <div className="card-action">
                        <Link to={`/Topic/${Topics[i][1]}/`} className="white-text">
                            CHECK THE CODE
                        </Link>
                    </div>
                </div>
            </div>    
        )

        const Card2 = i + 1 == Topics.length? null : (
            <div className="col s6">
                <div className={`card hoverable ${ColorsForCards[(i + 1) % ColorsForCards.length]}`}>
                    <div className="card-content white-text">
                        <span className="card-title">{Topics[i][0]}</span>
                    </div>
                    <div className="card-action">
                        <Link to={`/Topic/${Topics[i+1][1]}/`}>
                            See more
                        </Link>
                    </div>
                </div>
            </div>    
        )


        TopicsHTML.push(
            <div className="row" key={i}>
                {Card1}
                {Card2}
            </div>
        )
    }



    const HelloCard = (
        <div className="row">
            <div className="col s12">
                <div className="card" style={{backgroundColor: "#FFF8E1"}}>
                    <div className="card-content center blue-grey-text text-darken-3" 
                        style={{fontSize: "1.2rem"}}>
                        
                        <span className="card-title"><b>Hi, Welcome to THE REFERENCE</b></span>
                        
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

                        <a className="waves-effect waves-teal amber lighten-4 btn-flat">
                            GET THE PDF
                        </a>

                        <br />

                    </div>

                </div>
                
            </div>
        </div>
    )

    return (

        <div className="container">
            {HelloCard}
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