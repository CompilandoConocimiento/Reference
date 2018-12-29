import React from "react"
import { Link } from 'react-router-dom'

import { TopicData } from "../../Data/"

const colors = [
    "red lighten-2",
    "indigo lighten-2",
    "cyan lighten-1",
    "green lighten-2",
    "orange lighten-2",
    "brown lighten-2",
].sort(() => Math.random() - 0.5)


const buttonClassname = "hoverable btn-large col s12 m8 l6 offset-m2 offset-l3 "
const SubTopicButton: React.FunctionComponent<{link: string, classname: string}> = props => (
    <div className="row">
        <Link className={props.classname} to={props.link} onClick={() => scroll(0, 0)} >
            {props.children}
        </Link>
    </div>
)

const CardOfSubTopics: React.FunctionComponent<{TopicData: TopicData}> = props => (
    <div className="container">
        <div className="card-panel center">

            <h4 className="blue-grey-text text-darken-3">
                {props.TopicData.name}
            </h4>
            <br />
            <br />

            {
                props.TopicData.Algorithms.map( (Algorithm, index) => (
                    <SubTopicButton 
                        classname = {buttonClassname + colors[index % colors.length]}
                        link      = {`/Topic/${props.TopicData.link}/${Algorithm.link}`}
                        key       = {Algorithm.link}>
                            {Algorithm.name}
                    </SubTopicButton>
                ))
            }

        </div>
    </div>
)

export default CardOfSubTopics