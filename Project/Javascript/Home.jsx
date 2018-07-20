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
        "purple lighten-2",
        "teal lighten-2",
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
                        <Link to={`/Topic/${Topics[i][1]}/`}>
                            See more
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

    return (

        <div className="container">
            <div className="row">
                <div className="col s12">
                    
                    <div className="card amber lighten-5">
                        
                        <div className="card-content blue-grey-text text-darken-4">
                            
                            <span className="card-title">Hi, welcome to THE REFERENCE</span>
                            
                            <p>
                                Competitive programming Refence.
                            </p> 
                            
                            <p>
                                By CompilandoConocimiento
                            </p>

                        </div>

                    </div>
                    
                </div>
            </div>

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