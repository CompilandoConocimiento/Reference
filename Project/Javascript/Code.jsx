// =====================================================================
// ============                 IMPORTS            =====================
// =====================================================================
import React from "react"
import {Data} from "./Data"

// =====================================================================
// ============                 CODE               =====================
// =====================================================================
export default function Code (props) {

    const AlgorithmData = Data.Topics[props.TopicID].SubTopics.find( e => e.Link === props.match.params.Algorithm)

    return (
        <React.Fragment>
            <div className="row center blue-grey-text text-darken-3">
                <h3>{AlgorithmData.Name}</h3>
            </div>

            <div className="row">
                <div className="col s12">
                    
                    <div className="card green darken-1">
                        
                        <div className="card-content white-text">
                            
                            <span className="card-title">Hola</span>
                            
                            <p>Aqui un texto etsupido sobre de {props.match.params.Algorithm} 
                            basado en {props.Topic}</p>
                        </div>

                    </div>

                </div>
            </div>
        </React.Fragment>
    )
  
}