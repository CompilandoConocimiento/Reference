// =====================================================================
// ============                 IMPORTS            =====================
// =====================================================================
import React from "react"
import Code from "./Code"
import { Switch, Route } from 'react-router-dom'

// =====================================================================
// ============                 CODE               =====================
// =====================================================================
export default function Topic (props) {

    return (
        <Switch>
            {props.Data.map(
                (Topic) => (
                    <Route 
                        key    = {`${Topic[0][1]}`} 
                        path   = {`/Topic/${Topic[0][1]}/:Algorithm`}
                        render = { (props) => <Code {...props} Topic={Topic[0][1]} TopicID={Topic[0][2]} /> }
                    />
                )
            )}
        </Switch>

    )
  
}