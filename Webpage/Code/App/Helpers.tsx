import React from "react"

/**
   * A component to call when loading something
   */
export const Loading: React.FunctionComponent = () => (
    <div style={{width: "100%", padding: "4% 10% 4% 10%"}}>
        <div className="progress" style={{height: "16px", borderRadius: "8px"}}>
            <div className="indeterminate green lighten-1"></div>
        </div>
    </div>
)


/**
   * A component to call when something went wrong
   */
export const ErrorMessage: React.FunctionComponent = () => (
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

    </div>
)
