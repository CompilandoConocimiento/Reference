import React from "react"
import { Link } from 'react-router-dom'
import Topics from "../Data"
import Style from "./Home.css"

const HelloCard: React.StatelessComponent<{}> = () => {
  return (
    <div className="row">
      <div className="col s12">
        <div className="card" style={{backgroundColor: "#FFF8E1"}}>
          <div className="card-content center blue-grey-text text-darken-3" style={{fontSize: "1.2rem"}}>
            
            <span className="card-title" style={{fontWeight: 300}}>
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

            <a 
              href      = "https://compilandoconocimiento.github.io/Reference/Book/Reference.pdf" 
              target    = "_blank" 
              className = "btn-flat waves-effect amber lighten-4">
              GET THE PDF
            </a>

            <br />

          </div>
        </div>
      </div>
    </div>
  )
}

type CardProps = {
  name: string,
  materializeCSSColor: string,
  link: string
}

const CardToTopic: React.StatelessComponent<CardProps> = (props: CardProps) => {
  return (
    <Link to={`/Topic/${props.link}/`} onClick={() => scroll(0, 0)}>
      <span 
        className = {`card hoverable ${props.materializeCSSColor}`} 
        style     = {{"display": "block"}}>
        
        <span className="card-content white-text" style={{"display": "block"}}>
          <span className="card-title">
            {props.name}
          </span>
        </span>

        <span className="card-action" style={{"display": "block"}}>
          <span className="white-text">
            CHECK IT OUT!
          </span>
        </span>

      </span>
    </Link>

  )
}

const Home: React.StatelessComponent<{}> = () => {

  const colors: Array<string> = [
    "red lighten-2",
    "indigo lighten-2",
    "cyan lighten-1",
    "green lighten-2",
    "brown lighten-2",
  ].sort(() => Math.random() - 0.5)

  return (
    <div className="container">
      
      <HelloCard />
      
      <div className="row">
        <div className="col s12">
          <div className={Style.Wrapper}>
            {
              Topics.map ( (Topic, index) =>
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
      </div>

      <br /><br />
      <br /><br />
      <br /><br />

    </div>
  )
}

export default Home