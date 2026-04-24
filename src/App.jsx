import { BrowserRouter as Router, Routes, Route, Navigate } from 'react-router-dom';
import LoginPage from './components/LoginPage';
import Data from './components/Data';

// Protected Route Component
const ProtectedRoute = ({ children }) => {
  const isAuthenticated = localStorage.getItem('isAuthenticated') === 'true';
  return isAuthenticated ? children : <Navigate to="/" replace />;
};

const App = () => {
  return (
    <Router>
      <Routes>
        <Route path="/" element={
          <div className='bg-[url(./assets/Background.png)] bg-cover font-body'>
            <LoginPage />
          </div>
          } 
        />
        <Route
          path="/data"
          element={
            <ProtectedRoute>
              <div className='bg-[url(./assets/Background.png)] bg-cover font-body'>
                <Data />
              </div>
            </ProtectedRoute>
          }
        />
      </Routes>
    </Router>
  );
};

export default App;