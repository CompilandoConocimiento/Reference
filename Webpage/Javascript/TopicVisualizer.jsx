// =====================================================================
// ============                 IMPORTS            =====================
// =====================================================================
import React from "react"
import AlgorithmVisualizer from "./AlgorithmVisualizer"
import Topics from "./Data"
import { Link, Switch, Route } from 'react-router-dom'

// =====================================================================
// ============                 CODE               =====================
// =====================================================================
function ListOfSubTopics (props) {

    const ColorsForCards = [
        "red lighten-2",
        "indigo lighten-2",
        "cyan lighten-1",
        "green lighten-2",
        "orange lighten-2",
        "brown lighten-2",
    ].sort(() => Math.random() - 0.5)

    return (
        <div className="container">
            <div className="row">
                <div className="col s12">
                    <div className="card-panel">
                        
                        <div className="center">
                            <h4 className="blue-grey-text text-darken-3">
                                {props.Topic.Name}
                            </h4>
                            <br />
                            <br />
                        </div>

                        {props.Topic.SubTopics.map(
                            (SubTopic, SubTopicsIndex) =>  {

                                let ButtonStyle = "waves-effect hoverable btn-large col s12 m10 l8 offset-m1 offset-l2"
                                ButtonStyle = `${ButtonStyle} ${ColorsForCards[SubTopicsIndex % ColorsForCards.length]}`

                                return (
                                    <div className="row" key={SubTopic.Link}>
                                        <Link className={ButtonStyle} to={`/Topic/${props.Topic.Link}/${SubTopic.Link}`}>
                                            {SubTopic.Name}
                                        </Link>
                                    </div>
                                )
                            }
                        )}

                    </div>
                </div>
            </div>

            <br />
            <br />
            <br />
            <br />
            <br />

        </div>

    )
}

function ErrorMessage (props) {

    return (
        <div className="container">
            <div className="row">
                <div className="col s12">
                    <div className="card-panel">
                        
                        <div className="center">
                            <h4 className="blue-grey-text text-darken-3">
                                Error, Something did not go right. Sorry :(
                            </h4>
                            <br />
                            <br />
                        </div>

                    </div>
                </div>
            </div>

            <br /><br /><br /><br />
            <br /><br /><br /><br />
            <br /><br /><br /><br />
            <br /><br /><br /><br />
            <br /><br /><br /><br />

        </div>
    )
}


export default function TopicVisualizer (props) {

    const Topic = Topics.find( Topic => Topic.Link === props.match.params.NameOfTopic)
    if (Topic == undefined) return <ErrorMessage />

    return (
        <Switch>
            <Route 
                exact path = {`/Topic/${Topic.Link}/`}
                render     = { (props) => <ListOfSubTopics {...props} Topic={Topic} /> }
            />
            <Route 
                path   = {`/Topic/${Topic.Link}/:Algorithm/`}
                render = { 
                    (props) => {
                        const AlgorithmData = Topic.SubTopics.find( SubTopic => SubTopic.Link ===  props.match.params.Algorithm)
                        return <AlgorithmVisualizer {...props} Algorithm={AlgorithmData} Topic={Topic} key={Date.now()} />
                    }

                }
            />
        </Switch>
    )
  
}

