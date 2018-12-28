import React from "react"
import { Link } from 'react-router-dom'
import { DirectoryData } from "../../Data"
import * as Style from "./Styles.css"


const radius = "1.15rem"

const cardActionStyle = {
    borderTop: "2px solid rgba(255, 255, 255, 0.3)",
    borderRadius: `0rem 0rem ${radius} ${radius}`
}

const cardStyle = {
    height: "100%", 
    display: "grid", 
    borderRadius: `${radius} ${radius} ${radius} ${radius}`
}

const HelloCard: React.FunctionComponent<{}> = () => (
    <div 
        className = "card-panel center blue-grey-text text-darken-3"
        style     = {{backgroundColor: "#FFF8E1", fontSize: "1.2rem", borderRadius: `${radius} ${radius} ${radius} ${radius}`}}>
            
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

interface CardProps {
    name: string,
    materializeCSSColor: string,
    link: string
}

const CardToTopic: React.FunctionComponent<CardProps> = props => {
  return (
    <Link 
        to        = {`/Topic/${props.link}/`}
        onClick   = {() => scroll(0, 0)}
        style     = {cardStyle}
        className = {`card hoverable white-text ${props.materializeCSSColor}`}>
        
        <div className="card-content">
          <div className="card-title">{props.name}</div>
        </div>

        <div className="card-action" style={cardActionStyle}>
            CHECK IT OUT!
        </div>

    </Link>
  )
}

const colors = [
    "red lighten-2",
    "indigo lighten-2",
    "cyan lighten-1",
    "green lighten-2",
    "brown lighten-2",
].sort(() => Math.random() - 0.5)

const Home: React.FunctionComponent<{}> = () => (
    <div className="container">
        <HelloCard />
      
        <div className={Style.Wrapper}>
        {
            DirectoryData.map ( (Topic, index) =>
                <CardToTopic 
                    key		= {index} 
                    name	= {Topic.name} 
                    link	= {Topic.link}
                    materializeCSSColor = {colors[index % colors.length]} 
                />
            )
        }
        </div>
    </div>
)

export default Home