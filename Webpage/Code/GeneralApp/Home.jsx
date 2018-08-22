import React from "react"
import { Link } from 'react-router-dom'
import Topics from "../Data"
import Style from "./Home.css"

function HelloCard (props) {

    function ButtonToPDF (props) {
        return (
            <a 
                href      = "https://compilandoconocimiento.github.io/Reference/Book/Reference.pdf" 
                target    = "_blank" 
                className = "btn-flat waves-effect amber lighten-4">
                GET THE PDF
            </a>
        )
    }

    return (
        <div className="row">
            <div className="col s12">
                <div className="card" style={{backgroundColor: "#FFF8E1"}}>
                    <div className="card-content center blue-grey-text text-darken-3" style={{fontSize: "1.2rem"}}>
                        
                        <span className="card-title" style={{fontWeight: "300"}}>
                            Hi, Welcome to THE REFERENCE
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
        <div className={`card hoverable ${props.color}`}>
            
            <div className="card-content white-text">
                <span className="card-title">
                    {props.name}
                </span>
            </div>

            <div className="card-action">
                <Link to={`/Topic/${props.link}/`} className="white-text">
                    Check it out!
                </Link>
            </div>

        </div>
    )

}



export default function Home (props) {

    const colors = [
        "red lighten-2",
        "indigo lighten-2",
        "cyan lighten-1",
        "green lighten-2",
        "brown lighten-2",
    ].sort(() => Math.random() - 0.5)


    const TopicsCards = Topics.map ((Topic, index) => {
        const randomColor = colors[index % colors.length]
        return (
            <CardToTopic key={index} color={randomColor} name={Topic.Name} link={Topic.Link}/>
        )
    })

    return (

        <div className="container">
            <HelloCard />
            
            <div className="row">
                <div className="col s12">
                    <div className={Style.Wrapper}>
                        {TopicsCards}
                    </div>
                </div>
            </div>

            <br /><br /><br /><br /><br />

        </div>
    )
  
}