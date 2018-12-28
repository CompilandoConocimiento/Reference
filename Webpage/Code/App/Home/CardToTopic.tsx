import React from "react"
import { Link } from 'react-router-dom'

interface CardProps { name: string, materializeCSSColor: string, link: string, radius: string }
const CardToTopic: React.FunctionComponent<CardProps> = props => {

    const cardActionStyle = {
        borderTop: "2px solid rgba(255, 255, 255, 0.3)",
        borderRadius: `0rem 0rem ${props.radius} ${props.radius}`
    }

    const cardStyle = {
        height: "100%", 
        display: "grid", 
        borderRadius: `${props.radius} ${props.radius} ${props.radius} ${props.radius}`
    }

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

export default CardToTopic